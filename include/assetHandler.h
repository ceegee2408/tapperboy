#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H

#include "bitmaps.h"

enum AssetIndex
{
    BAR_BACKGROUND = 0,
    PLAYER_STANDING = 1,
    PLAYER_FILLING = 2,
    BEER_FILLED = 3,
    BEER_EMPTY = 4,
    BEER_FILL = 5,
    BEER_TUMBLE = 6
};

class Asset {
public:
    const uint8_t* bitmap;
    
    uint8_t width() const { return pgm_read_byte(bitmap); }
    uint8_t height() const { return pgm_read_byte(bitmap + 1); }
    const uint8_t* data() const { return (bitmap + 2); }
};

class AssetHandler
{
private:
     inline static constexpr Asset assets[7] = {
        {bar_background_bitmap},
        {player_standing_bitmap},
        {player_filling_bitmap},
        {beer_filled_bitmap},
        {beer_empty_bitmap},
        {beer_fill_bitmap},
        {beer_tumble_bitmap}
    };

public:
    static const Asset *get(AssetIndex idx)
    {
        return &assets[idx];
    }
};

#endif // ASSETHANDLER_H
