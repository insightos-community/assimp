#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <cstdio>
#include <cstring>
int main() {
  const char mesh[]="v 0 0 0\nv 1 0 0\nv 0 1 0\nf 1 2 3\n";
  const aiScene* scene=aiImportFileFromMemory(mesh,std::strlen(mesh),aiProcess_Triangulate,"obj");
  if (!scene) { std::puts(aiGetErrorString()); return 1; }
  bool valid=scene->mNumMeshes==1 && scene->mMeshes[0]->mNumFaces==1;
  aiReleaseImport(scene);
  if (!valid) return 2;
  std::puts("PASS: Assimp OBJ triangle import");
}
