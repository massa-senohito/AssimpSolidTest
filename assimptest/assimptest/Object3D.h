#pragma once

#define let auto
class Object3D
{
  class Impl;
  Impl* impl;
public:
  //���_����Model3D�Ŏ������I���Ă���̂ŁA�p�X�ƍ��W�ŃI�u�W�F�N�g�\������ق���
  Object3D(float* vertices, int count);
  ~Object3D();
  //virtual 
    void Render();
  void SetPos(float*);
  
};

