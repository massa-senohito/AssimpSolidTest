#pragma once
#include "include\solid\SOLID.h"

typedef std::vector<float> Verts;
typedef const char* cstring;
class Collision
{
  Verts* verts;
  DT_SceneHandle scene;
public:
  Collision();
  void AddPoint(float v[3]);
  //void Position();
  //DT_SetPosition
  //void Orientation();
  void RenderTree();
  ~Collision();
};

