//
//  ChangeColorBy.hpp
//  TestProject
//
//  Created by Kazuki Oda on 2016/07/24.
//
//

#ifndef ChangeColorBy_hpp
#define ChangeColorBy_hpp

#include <stdio.h>
#include "cocos2d.h"

enum class ChangeColorType { RGB, HSV };
class ChangeColorBy : public cocos2d::ActionInterval {
   private:
    ChangeColorType m_type;
    cocos2d::Vec3 m_color;
    bool m_reverse;

   public:
    static ChangeColorBy *create(const ChangeColorType &type,
                                 const cocos2d::Vec3 &color, bool doReverse,
                                 float duration);
    void update(float f) override;
    virtual void startWithTarget(cocos2d::Node *target) override;
    virtual ActionInterval *clone() const override;

   protected:
    virtual bool initWithDuration(const ChangeColorType &type,
                                  const cocos2d::Vec3 &color, bool doReverse,
                                  float duration);

   private:
    void setShaderWithTarget(cocos2d::Node *target, const GLchar *vert,
                             const GLchar *flag);
};

#endif /* ChangeColorBy_hpp */
