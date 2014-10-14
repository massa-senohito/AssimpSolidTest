// assimptest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Model3D.h"
#include "include\GL\freeglut.h"
#define let auto
Model3D* model;
int count = 0;

void OnDraw(){
  glRotatef(1, 0.5, 1, 0.25);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  static float wid = 320.0 / 160.0;
  static float hei = 240.0 / 160.0;
  //wid = 180;
  //hei= 180;
  glOrtho(-wid, wid, -hei, hei, -50, 50);
  
  glMatrixMode(GL_MODELVIEW);

  model->Render();
  glutSwapBuffers();
}
void OnExit(){
  //関連付けられたアセット全リリース
  let errstr = aiGetErrorString();
  delete model;

}
void timer(int value)
{
  //oneCall(getStenc);
  count++;
  glutPostRedisplay();
  //update(pushed);

  glutTimerFunc(value,timer,17); //タイマー関数
}
int _tmain(int argc, _TCHAR* argv[])
{
  let path = "C:\\Users\\master8\\Documents\\cube.blend";

  //let scene=aiImportFile(path, aiProcessPreset_TargetRealtime_Fast);
  //let hasTex=scene->HasTextures();
  //let hasMat=scene->HasMaterials();
  //let meshs = scene->mMeshes;
  //let verts=meshs[0]->mNumVertices;
  model=new Model3D(path);
  char* ar = "";
  glutInit(&argc, nullptr);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
  glutInitWindowSize(640, 480);
  glutCreateWindow("assimp test");
  glClearColor(0, 1, 0, 1);
  glutDisplayFunc(OnDraw);
  glutTimerFunc(0,timer,17);
  glutCloseFunc(OnExit);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glutMainLoop();
	return 0;
}

