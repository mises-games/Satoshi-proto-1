#include "stpch.h"
#include "Samples.h"

#include <Satoshi/Input.h>
#include <Satoshi/KeyCodes.h>
#include <glm/glm.hpp>
#include <DirectXMath.h>
#include <glm/gtx/transform.hpp>
#include <Satoshi/Log.h>


void Satoshi::Sample1()
{
	glm::mat4 glTranslate = glm::translate(glm::mat4(1.0), glm::vec3(1.5f, 2.0f, 2.0f));
	DirectX::XMMATRIX dxTranslate = DirectX::XMMatrixTranslation(1.5f, 2.0f, 3.0f);
	if (Satoshi::Input::IsKeyPressed(ST_KEY_Q))
		ST_CORE_INFO("Key Q Pressed");
	float horizontal = Satoshi::Input::GetAxisRawHorizontal();
	if (horizontal != 0.0f)
		ST_CORE_INFO("Horizontal move {0}", horizontal);
	float vertical = Satoshi::Input::GetAxisRawVertical();
	if (vertical != 0.0f)
		ST_CORE_INFO("Vertical move {0}", vertical);
	
}
