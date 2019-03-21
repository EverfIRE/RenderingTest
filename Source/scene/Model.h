#include "Utils/Struct.h"
#include <Utils/Enum.h>
#include "Utils/Utils.h"

struct QVertexData {
	float position[3];
	float normal[3];
	float texcoord[2];
};
class Model
{
	QVertexData*mVertexesData;
	unsigned short* mIndexes;
	int mIndexCount;

//public function
public:
	GLuint mTexture;
	Model();
	void Init(const char*TexPath);
	void Draw();
//private variable
private:

//Private Function
private:
	unsigned char * DecodeObj(unsigned char * bmpFileData);
};
