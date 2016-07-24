//
//  Shaders.cpp
//  TestProject
//
//  Created by Kazuki Oda on 2016/07/24.
//
//

#include "Shaders.hpp"
#define STRINGIFY(A) #A
namespace cocos2d {
#include "shaders/light_rgb.frag"
#include "shaders/light_rgb.vert"

#include "shaders/light_hsv.frag"
#include "shaders/light_hsv.vert"
};