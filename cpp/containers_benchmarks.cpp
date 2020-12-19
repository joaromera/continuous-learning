#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <unordered_map>

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

struct Clip
{
    int id;
    std::string name;
    int startTime;
    int endTime;

    Clip() = default;
    Clip(int pId, const std::string &pName, int pStartTime, int pEndTime) : id(pId), name(pName), startTime(pStartTime), endTime(pEndTime) {}
    Clip(const Clip&) = default;
    Clip& operator=(const Clip&) = default;
};

using UnorderedStringToClipMap = std::unordered_map<std::string, Clip>;
using StringToClipMap = std::map<std::string, Clip>;
using UnorderedStringToClipMultiMap = std::unordered_multimap<std::string, Clip>;
using StringToClipMultiMap = std::multimap<std::string, Clip>;

template<typename T>
void insertClips(T& clip_container, const std::vector<Clip>& vec)
{
    for (const auto &clip : vec)
    {
        clip_container.emplace(clip.name, clip);
    }
}

template<typename T>
Clip lookup(T& container, const std::string &clip)
{
    return container.find(clip)->second;
}

template<typename T>
std::list<Clip> multi_lookup(T& container, const std::string &clip)
{
    std::list<Clip> output;
    for (auto [begin, end] = container.equal_range(clip); begin != end; )
    {
        output.push_front(begin->second);
        ++begin;
    }
    return output;
}

TEST_CASE("Insertion and lookup on associative containers")
{
    std::vector<Clip> vec;
    vec.reserve(1'000'000);

    for (int i = 0; i < 1'000'000; ++i)
    {
        int id = rand() % 1'000'000;
        std::stringstream ss;
        ss << "name " << id;
        vec.emplace_back(id, ss.str(), rand() % 1'000'000, rand() % 1'000'000);
    }

    BENCHMARK("Unordered insertion")
    {
        UnorderedStringToClipMap unordered_clips;
        return insertClips(unordered_clips, vec);
    };

    BENCHMARK("Ordered insertion")
    {
        StringToClipMap ordered_clips;
        return insertClips(ordered_clips, vec);
    };

    BENCHMARK("MULTI Unordered insertion")
    {
        UnorderedStringToClipMultiMap unordered_clips;
        return insertClips(unordered_clips, vec);
    };

    BENCHMARK("MULTI Ordered insertion")
    {
        StringToClipMultiMap ordered_clips;
        return insertClips(ordered_clips, vec);
    };

    UnorderedStringToClipMap unordered_clips;   insertClips(unordered_clips, vec);
    StringToClipMap ordered_clips;              insertClips(ordered_clips, vec);

    BENCHMARK("Unordered lookup")
    {
        Clip clip = vec[rand() % vec.size()];
        return lookup(unordered_clips, clip.name);
    };

    BENCHMARK("Ordered lookup")
    {
        Clip clip = vec[rand() % vec.size()];
        return lookup(ordered_clips, clip.name);
    };

    UnorderedStringToClipMultiMap multiunordered_clips;   insertClips(multiunordered_clips, vec);
    StringToClipMultiMap multiordered_clips;              insertClips(multiordered_clips, vec);

    auto rand_clip = vec[rand() % vec.size()];
    for (int i = 0; i < 999; ++i)
    {
        multiunordered_clips.emplace(rand_clip.name, rand_clip);
        multiordered_clips.emplace(rand_clip.name, rand_clip);
    }

    BENCHMARK("Unordered multi_lookup")
    {
        return multi_lookup(multiunordered_clips, rand_clip.name);
    };

    BENCHMARK("Ordered multi_lookup")
    {
        return multi_lookup(multiordered_clips, rand_clip.name);
    };

    REQUIRE(multi_lookup(multiunordered_clips, rand_clip.name).size() == 1000);
    REQUIRE(multi_lookup(multiordered_clips, rand_clip.name).size() == 1000);
}
