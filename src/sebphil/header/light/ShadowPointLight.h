#pragma once
#include <memory>
#include "PointLight.h"
#include "shader/ShaderProgram.h"
#include "modelstructure/Model.h"

class ShadowPointLight : public PointLight{

private:

	uint32_t cubeMap;
	uint32_t framebuffer;
	uint32_t shadowWidth;
	uint32_t shadowHeight;

	float far, near, aspRatio;

	glm::mat4 projMat;
	glm::mat4 lightSpaceMat[6];

	void setUpTexture();
	void generateTexture();
	void bindTexture();
	void fillTexture();
	void setTexParams();
	void setUpFramebuffer();
	void generateProjMat();
	void generateLightSpaceMat();

	void updateLightSpaceMat(ShaderProgram& shadowProgram);
	void renderModels(const std::vector<std::shared_ptr<Model>>& models, ShaderProgram& shadowProgram);
	void updateShadow(ShaderProgram& program, ShaderProgram& shadowProgram);

public:

	ShadowPointLight();

	void update(const std::vector<std::shared_ptr<Model>>& models, ShaderProgram& shadowProgram, ShaderProgram& program);

	void setPosition(glm::vec3 position);

};