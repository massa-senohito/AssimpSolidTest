#include "stdafx.h"
//http://d.hatena.ne.jp/setuna-kanata/20100721/1279731858/
template< typename Vertex >
class VertexBuffer
  : public BufferObject
{
public:
  /**
  *  ���_�z��Ńo�b�t�@���X�V
  */
  void update(int offset, int vertex_count, const Vertex* vertex)
  {
    BufferObject::update(offset, sizeof(Vertex), vertex_count, vertex);
  }

public:
  /**
  *  ���_�z��Ńo�b�t�@�̐����A���������s���B
  *  vertex��nullptr���w�肵���ꍇ�Avertex_count�̃T�C�Y�Ńo�b�t�@�̐����̂ݍs���B
  *
  *  @param  vertex_count    ���_��
  *  @param  vertex          ���_�z��̐擪�A�h���X
  */
  VertexBuffer(int vertex_count, const Vertex* vertex = nullptr)
    : BufferObject(GL_ARRAY_BUFFER_ARB, sizeof(Vertex), vertex_count, vertex)
  {
  }

};

struct SpriteBatchVertex
{
  float x, y;         ///<    �Ƃ肠����2D
  float r, g, b, a;   ///<    unsigned char�̕����ǂ�����
  float tu, tv;       ///<    �e�N�X�`�����W
};
//
//class SpriteBatch
//{
//public:
//  /**
//  *  ���_�o�b�t�@�ɃX�v���C�g��ǉ��B
//  */
//  void add(const TexturePtr& texture, const Recti& rect, const Color& color);
//  /**
//  *  ���_�o�b�t�@�ɗ��߂��Ă���X�v���C�g���܂Ƃ߂ĕ`��B
//  */
//  void draw();
//
//public:
//  SpriteBatch(GLushort sprite_count);
//
//private:
//  VertexBuffer< SpriteBatchVertex > vertex;   ///<    sprite_count * 4�̒��_
//  IndexBuffer index;                          ///<    sprite_count * 6�̃C���f�b�N�X
//  int current;                                ///<    ���݂̃X�v���C�g��
//  int sprite_count;                           ///<    �X�v���C�g�̍ő吔
//  std::shared_ptr< OpenGLTexture > texture;   ///<    ���݂̃X�v���C�g�Ŏg���Ă���e�N�X�`��
//};
//