#include "Model.h"


Model::Model()
{
	memset(mAmbientMaterial, 0, sizeof(mAmbientMaterial));
	memset(mDiffuseMaterial, 0, sizeof(mDiffuseMaterial));
	memset(mSpecularMaterial, 0, sizeof(mSpecularMaterial));
}

void Model::Init(const char* ObjPath)
{
	ModelType _modelType=ModelType::OBJ;

	char* _ObjPath = new char[256];
	strcpy(_ObjPath, ObjPath);

	int _fileSize=0;
	unsigned char* _fileData= LoadFileContent(_ObjPath,_fileSize);
	if (_fileData==nullptr)
	{
		return;
	}

	switch (_modelType)
	{
		case ModelType::THREEDS:
			break;
		case ModelType::OBJ:
			DecodeObj(_fileData);
			delete _fileData;
			break;
		case ModelType::FBX:
			break;
		case ModelType::DEFAULT:
			break;
		default:
			break;
	}
}

void Model::Draw()
{
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D,mTexture);
	glDisable(GL_TEXTURE_2D);
	glMaterialf(GL_FRONT,GL_SHININESS, 64.0f);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mAmbientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mDiffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mSpecularMaterial);
	glPushMatrix();
	glTranslatef(0.0f,0.0f,-5.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < mIndexCount; i++)
	{
		glTexCoord2fv(mVertexesData[mIndexes[i]].texcoord);
		glNormal3fv(mVertexesData[mIndexes[i]].normal);
		glVertex3fv(mVertexesData[mIndexes[i]].position);
	}
	glEnd();
	glPopMatrix();
}

unsigned char* Model::DecodeObj(unsigned char * bmpFileData)
{
	std::vector<QFloatData>positions,normals;
	std::vector<QFloatData>texcoords;
	std::vector<QFaceIndex>faceIndexs;
	std::vector<int>indexes;

	std::stringstream sFileContent((char*)bmpFileData);
	std::string temp;
	char szOneLine[256];
	while (!sFileContent.eof())
	{
		memset(szOneLine, 0, 256);
		sFileContent.getline(szOneLine, 256);
		if (strlen(szOneLine)>0)
		{
			if (szOneLine[0]=='v')
			{
				std::stringstream ssOneLine(szOneLine);
				if (szOneLine[1]=='t')
				{
					ssOneLine >> temp;
					QFloatData texcoord;
					ssOneLine >> texcoord.v[0];
					ssOneLine >> texcoord.v[1];
					texcoords.push_back(texcoord);
					printf("texcoord: x %f,y %f\n",texcoord.v[0],texcoord.v[1]);
				}
				else if(szOneLine[1]=='n')
				{
					ssOneLine >> temp;
					QFloatData normal;
					ssOneLine >> normal.v[0];
					ssOneLine >> normal.v[1];
					ssOneLine >> normal.v[2];
					normals.push_back(normal);
					printf("normal: x %f,y %f,z %f\n", normal.v[0],normal.v[1],normal.v[2]);
				}
				else
				{
					ssOneLine >> temp;
					QFloatData position;
					ssOneLine >> position.v[0];
					ssOneLine >> position.v[1];
					ssOneLine >> position.v[2];
					positions.push_back(position);
					printf("position: x %f,y %f,z %f\n", position.v[0],position.v[1],position.v[2]);
				}
			}
			else if ( szOneLine[0]=='f')
			{
				std::stringstream ssOneLine(szOneLine);
				ssOneLine >> temp;
				std::string vertexStr;
				for (int i = 0; i < 3; i++)
				{
					ssOneLine >> vertexStr;
					size_t pos = vertexStr.find_first_of('/');
					std::string posIndexStr = vertexStr.substr(0,pos);
					size_t pos2 = vertexStr.find_first_of('/',pos+1);
					std::string texcoordIndexStr = vertexStr.substr(pos+1,pos2-1-pos);
					std::string normalIndexStr = vertexStr.substr(pos2+1,vertexStr.length()-1-pos2);
					QFaceIndex faceindex;
					faceindex.posIndex = atoi(posIndexStr.c_str());
					faceindex.texcoordIndex = atoi(texcoordIndexStr.c_str());
					faceindex.normalIndex = atoi(normalIndexStr.c_str());
					int nCurrentVertexIndex = -1;
					int nCurrentVertexCount = (int)faceIndexs.size();
					for (int j = 0; j < nCurrentVertexCount; j++)
					{
						if (faceIndexs[j].posIndex== faceindex.posIndex&&
							faceIndexs[j].normalIndex==faceindex.normalIndex&&
							faceIndexs[j].texcoordIndex==faceindex.texcoordIndex)
						{
							nCurrentVertexIndex = j;
							break;
						}
					}
					if (nCurrentVertexIndex==-1)
					{
						nCurrentVertexIndex = (int)faceIndexs.size();
						faceIndexs.push_back(faceindex);
					}
					indexes.push_back(nCurrentVertexIndex);
				}
			}
		}
	}
	mIndexCount = (int)indexes.size();
	mIndexes = new unsigned short[mIndexCount];
	for (int i = 0; i < mIndexCount; i++)
	{
		mIndexes[i] = indexes[i];
	}
	int vertexCount = (int)faceIndexs.size();
	mVertexesData = new QVertexData[vertexCount];
	for (int i = 0; i < vertexCount; ++i) {
		memcpy(mVertexesData[i].position, positions[faceIndexs[i].posIndex - 1].v, sizeof(float) * 3);
		memcpy(mVertexesData[i].texcoord, texcoords[faceIndexs[i].texcoordIndex - 1].v, sizeof(float) * 2);
		memcpy(mVertexesData[i].normal, normals[faceIndexs[i].normalIndex - 1].v, sizeof(float) * 3);
	}
	return nullptr;
}

void Model::SetAmbientMaterial(float r, float g, float b, float a)
{
	mAmbientMaterial[0] = r;
	mAmbientMaterial[1] = g;
	mAmbientMaterial[2] = b;
	mAmbientMaterial[3] = a;
}

void Model::SetDiffuseMaterial(float r, float g, float b, float a)
{
	mDiffuseMaterial[0] = r;
	mDiffuseMaterial[1] = g;
	mDiffuseMaterial[2] = b;
	mDiffuseMaterial[3] = a;
}

void Model::SetSpecularMaterial(float r, float g, float b, float a)
{
	mSpecularMaterial[0] = r;
	mSpecularMaterial[1] = g;
	mSpecularMaterial[2] = b;
	mSpecularMaterial[3] = a;
}
