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


enum CALLBACK_ID {
    CALLBACK_ID_NONE = -1,
    CALLBACK_ID_0 = 0,
    CALLBACK_ID_1,
    CALLBACK_ID_2,
    CALLBACK_ID_3,
    CALLBACK_ID_4,
    CALLBACK_ID_5,
    CALLBACK_ID_6,
    CALLBACK_ID_7,
    CALLBACK_ID_8,
    CALLBACK_ID_9,
    CALLBACK_ID_10,
    CALLBACK_ID_11,
    CALLBACK_ID_12,
    CALLBACK_ID_13,
    CALLBACK_ID_14,
    CALLBACK_ID_15,
    CALLBACK_ID_16,
    CALLBACK_ID_17,
    CALLBACK_ID_18,
    CALLBACK_ID_19,
    CALLBACK_ID_20,
    CALLBACK_ID_21,
    CALLBACK_ID_22, // by NoOne: UniMissileBurst();
    CALLBACK_ID_23, // by NoOne: makeMissileBlocking();
    kCallbackMax
};

extern void (*gCallback[kCallbackMax])(int);