#include "stdafx.h"
#include "TempSoundScene.h"

HRESULT TempSoundScene::init(void)
{
   // TEMPSOUNDMANAGER->addMp3FileWithKey("bgm", "Resources/Sounds/01ENTERTHEGUN.mp3");
    //TEMPSOUNDMANAGER->addWaveFileWithKey("eft", "Resources/Sounds/dragun_transform_01_001.wav");
    TEMPSOUNDMANAGER->addWaveFileWithKey("test", "Resources/Sound/00_Coin_Inserted.mp3");
    return S_OK;
}

void TempSoundScene::update(void)
{
    if (KEYMANAGER->isOnceKeyDown('P'))
    {
        //TEMPSOUNDMANAGER->playSoundWithKey("bgm");
        TEMPSOUNDMANAGER->playSoundWithKey("test");
    }
    if (KEYMANAGER->isOnceKeyDown('O'))
    {
        //TEMPSOUNDMANAGER->playEffectSoundWave("Resources/Sounds/dragun_blade_01.wav");
    }
}
