#pragma once

class Co_Info {
private:
    inline static char selectedMusicFile[32]{}; //パスが入る
    Co_Info() = delete;
public:
    static void setMusicFile(const char* fileName);
    static const char* getMusicFileName();
};