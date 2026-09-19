#pragma once

#include <cstdint>
#include <cstddef>

class Music {
private:
    inline static uint8_t* introBuffer{nullptr};
    inline static size_t introFileSize{};
    inline static uint8_t* loopBuffer{nullptr};
    inline static size_t loopFileSize{};
    inline static char loopName[30]{};
    inline static bool exi_intro{false};
    inline static bool isPlayingIntro = false; 
    Music() = delete;
public:
    static void init();
    static bool memory_for_music(const char* musicFileName);
    static void play();
    static void update();
    static void fina();
};