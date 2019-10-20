//-------------------------------------------------------------------------
/*
Copyright (C) 2010-2019 EDuke32 developers and contributors
Copyright (C) 2019 Nuke.YKT

This file is part of NBlood.

NBlood is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License version 2
as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
//-------------------------------------------------------------------------
#pragma once
#include "callback.h"

enum {
    kChannelZero = 0,
    kChannelSetTotalSecrets,
    kChannelSecretFound,
    kChannelTextOver,
    kChannelLevelExitNormal,
    kChannelLevelExitSecret,
    kChannelModernEndLevelCustom, // // custom level end
    kChannelLevelStartSinglePlayer,
    kChannelLevelStartMatch, // DM and TEAMS
    kChannelLevelStartCoop,
    kChannelLevelStartTeamsOnly,
    kChannelPlayerDeathTeamA = 15,
    kChannelPlayerDeathTeamB,
    kChannelMapExtended = 60, // map requires modern features to work properly
    kChannelTeamAFlagCaptured = 80,
    kChannelTeamBFlagCaptured,
    kChannelRemoteBomb0 = 90,
    kChannelRemoteBomb1,
    kChannelRemoteBomb2,
    kChannelRemoteBomb3,
    kChannelRemoteBomb4,
    kChannelRemoteBomb5,
    kChannelRemoteBomb6,
    kChannelRemoteBomb7,
};

#define kMaxChannels 4096

struct RXBUCKET
{
    unsigned int index : 13;
    unsigned int type : 3;
};
extern RXBUCKET rxBucket[];
extern unsigned short bucketHead[];

enum COMMAND_ID {
    kCmdOff = 0,
    kCmdOn = 1,
    kCmdState = 2,
    kCmdToggle = 3,
    kCmdNotState = 4,
    kCmdLink = 5,
    kCmdLock = 6,
    kCmdUnlock = 7,
    kCmdToggleLock = 8,
    kCmdStopOff = 9,
    kCmdStopOn = 10,
    kCmdStopNext = 11,
    kCmdCounterSector = 12,
    kCmdCallback = 20,
    kCmdRepeat = 21,
    
    kCmdSpritePush = 30,
    kCmdSpriteImpact = 31,
    kCmdSpritePickup = 32,
    kCmdSpriteTouch = 33,
    kCmdSpriteSight = 34,
    kCmdSpriteProximity = 35,
    kCmdSpriteExplode = 36,
    
    kCmdSectorPush = 40,
    kCmdSectorImpact = 41,
    kCmdSectorEnter = 42,
    kCmdSectorExit = 43,

    kCmdWallPush = 50,
    kCmdWallImpact = 51,
    kCmdWallTouch = 52,

    kCmdModernUse = 53, // used by most of modern types
    kCmdNumberic = 64, // 64: 0, 65: 1 and so on up to 255
    kCmdModernFeaturesEnable = 100, // must be in object with kChannelMapExtended RX / TX
    kCmdModernFeaturesDisable = 200, // must be in object with kChannelMapExtended RX / TX
    kCmdNumbericMax = 255,
};

struct EVENT {
    unsigned int index : 14; // index
    unsigned int type : 3; // type
    unsigned int cmd : 8; // cmd
    unsigned int funcID : 8; // callback
};

void evInit(void);
char evGetSourceState(int nType, int nIndex);
void evSend(int nIndex, int nType, int rxId, COMMAND_ID command);
void evPost(int nIndex, int nType, unsigned int nDelta, COMMAND_ID command);
void evPost(int nIndex, int nType, unsigned int nDelta, CALLBACK_ID a4);
void evProcess(unsigned int nTime);
void evKill(int a1, int a2);
void evKill(int a1, int a2, CALLBACK_ID a3);