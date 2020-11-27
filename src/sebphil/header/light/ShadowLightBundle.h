#pragma once
#include "shader/ShaderProgram.h"
#include "structure/Model.h"
#include "ShadowDirLight.h"
#include "ShadowPointLight.h"
#include <vector>

class ShadowLightBundle {

public:
	ShadowDirLight dirLight;
	ShadowPointLight pointLight;

	void update(std::vector<Model*>& models, ShaderProgram& shadowProgram, ShaderProgram& pointShadowProgram, ShaderProgram& program);

	void enableDirLight(ShaderProgram& program);
	void disableDirLight(ShaderProgram& program);

	void enablePointLight(ShaderProgram& program);
	void disablePointLight(ShaderProgram& program);

};