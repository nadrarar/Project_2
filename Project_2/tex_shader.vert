#version 400

layout (location = 0) in vec3 VertexPosition;
uniform mat4 mvp;
out vec4 texCoordinate;

void main()
{

	texCoordinate=vec4(0.5f+0.5f*VertexPosition.x,0.5f+0.5f*VertexPosition.y,0.0f,1.0f);
	gl_Position = mvp*vec4(VertexPosition, 1.0);
}
