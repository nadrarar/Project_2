#version 400
in vec3 Position;

layout (location = 0) out vec4 FragColor;
in vec4 texCoordinate;

void main()
{
		if(texCoordinate.y<0.36f)
			FragColor = vec4(1.0f);
		else
			FragColor = texCoordinate;
}
