#pragma once

#define let auto
class Object3D
{
  class Impl;
  Impl* impl;
public:
  //頂点情報はModel3Dで実装し終えているので、パスと座標でオブジェクト表現するほうが
  Object3D(float* vertices, int count);
  ~Object3D();
  //virtual 
    void Render();
  void SetPos(float*);
  
};

