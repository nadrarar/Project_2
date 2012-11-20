#version 400
in vec3 Position;

layout (location = 0) out vec4 FragColor;
in vec4 texCoordinate;

void main()
{
		if(texCoordinate.y<0.36f)
			FragColor = vec4(1.0f,1.0f,0.0f,1.0f);
		//else
			FragColor = vec4(texCoordinate.xyz,1.0f);
}
