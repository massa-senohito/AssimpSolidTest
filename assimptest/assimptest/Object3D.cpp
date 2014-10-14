#include "stdafx.h"
#include "Object3D.h"
#include "assimp\vector3.h"
class Object3D::Impl
{
  /*
public:
  Impl(Vlist* vertices, int vcount):_pos(V3(0)){
    _vert = std::move(vertices);
  }
  void SetPos(V3& pos){
    _pos = (pos);
  }
  ~Impl(){
    _vert->clear();
    delete _vert;
    delete &_pos;
  }
private:
  Vlist* _vert;
  V3& _pos;
  */
};

Object3D::Object3D(float* vertices,int count)
{
  /*
  Vlist* tmpVerts = new Vlist();
  for (size_t i = 0; i < count; i++)
  {
    let v = new V3(vertices[0], vertices[i+1], vertices[i+2]);
    tmpVerts->push_back(v);
  }
  impl = new Impl(tmpVerts, count);
  */
}
void Object3D::SetPos(float* pos){
  /*
  impl->SetPos(V3(pos[0],pos[1],pos[2]));
  */
}
void Object3D::Render(){

}
Object3D::~Object3D()
{
}
