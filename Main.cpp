#include <glad/glad.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <Shader.hpp>

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	sf::Window window(sf::VideoMode(800, 600), "Chimpey!", sf::Style::Default, settings);

	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(sf::Context::getFunction)))
	{
		std::cout << "Failed to initialized GLAD!\n";
		return EXIT_FAILURE;
	}

	std::cout << "Vendor:" << glGetString(GL_VENDOR) << '\n';
	std::cout << "Version:" << glGetString(GL_VERSION) << '\n';
	std::cout << "Renderer:" << glGetString(GL_RENDERER) << '\n';

	std::vector<GLfloat> cubeVertices
	{
		// position				// color				// texcoord
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f, // 0
		-0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 2
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 0.0f, // 3

		0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 0.0f, // 3
		0.5f, -0.5f, -0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f, // 1
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f, // 0

		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		0.0f, 1.0f, // 4
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		0.0f, 0.0f, // 0
		0.5f, -0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f, // 1

		0.5f, -0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f, // 1
		0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 1.0f, // 5
		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		0.0f, 1.0f, // 4

		-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 1.0f, // 6
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 2
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 0.0f, // 0

		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 0.0f, // 0
		-0.5f, 0.5f, -0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f, // 4
		-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 1.0f, // 6

		0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f, // 7
		0.5f, -0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 0.0f, // 3
		0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 0.0f,		1.0f, 0.0f, // 1

		0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 0.0f,		1.0f, 0.0f, // 1
		0.5f, 0.5f, -0.5f,		1.0f, 1.0f, 0.0f,		1.0f, 1.0f, // 5
		0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f, // 7

		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 4
		-0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 6
		0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 7

		0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 7
		0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 5
		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 4

		-0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 1.0f,		0.0f, 1.0f, // 6
		-0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 2
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 1.0f,		1.0f, 0.0f, // 3

		0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 1.0f,		1.0f, 0.0f, // 3
		0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 1.0f,		1.0f, 1.0f, // 7
		-0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 1.0f,		0.0f, 1.0f, // 6
	};

	std::vector<GLfloat> screenQuadVertices
	{
		// position		// texcoord
		-1.0f, 1.0f,	0.0f, 1.0f,
		-1.0f, -1.0f,	0.0f, 0.0f,
		1.0f, -1.0f,	1.0f, 0.0f,

		-1.0f, 1.0f,	0.0f, 1.0f,
		1.0f, -1.0f,	1.0f, 0.0f,
		1.0f, 1.0f,		1.0f, 1.0f,
	};

	Shader shader("resources/shaders/vertex.glsl", "resources/shaders/fragment.glsl");
	shader.use();
	shader.setInt("Image", 0);

	Shader screenShader("resources/shaders/framebuffer/vertex.glsl", "resources/shaders/framebuffer/fragment.glsl");
	screenShader.use();
	screenShader.setInt("ScreenTexture", 0);

	sf::Image image;
	image.loadFromFile("resources/textures/marble.jpg");

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint vboCube;
	glGenBuffers(1, &vboCube);
	glBindBuffer(GL_ARRAY_BUFFER, vboCube);
		glBufferData(GL_ARRAY_BUFFER, cubeVertices.size() * sizeof(GLfloat), cubeVertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint vaoCube;
	glGenVertexArrays(1, &vaoCube);
	glBindVertexArray(vaoCube);
	glBindBuffer(GL_ARRAY_BUFFER, vboCube);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	GLuint vaoGround;
	glGenVertexArrays(1, &vaoGround);
	glBindVertexArray(vaoGround);
	glBindBuffer(GL_ARRAY_BUFFER, vboCube);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// -- frame buffer start
	GLuint fbo;
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	GLuint fboTexture;
	glGenTextures(1, &fboTexture);
	glBindTexture(GL_TEXTURE_2D, fboTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, window.getSize().x, window.getSize().y, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTexture, 0);

	GLuint rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, window.getSize().x, window.getSize().y);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	// -- frame buffer end

	GLuint vboScreenQuad;
	glGenBuffers(1, &vboScreenQuad);
	glBindBuffer(GL_ARRAY_BUFFER, vboScreenQuad);
		glBufferData(GL_ARRAY_BUFFER, screenQuadVertices.size() * sizeof(GLfloat), screenQuadVertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint vaoScreenQuad;
	glGenVertexArrays(1, &vaoScreenQuad);
	glBindVertexArray(vaoScreenQuad);
	glBindBuffer(GL_ARRAY_BUFFER, vboScreenQuad);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		const float timeAsSeconds = clock.getElapsedTime().asSeconds();

		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 view = glm::lookAt(
			glm::vec3(glm::cos(timeAsSeconds) * 5.0f, 2.0f, glm::sin(timeAsSeconds) * 5.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
		);

		glm::mat4 projection = glm::perspective(
			glm::radians(45.0f),
			static_cast<float>(window.getSize().x) / window.getSize().y,
			0.1f,
			100.0f
		);

		glm::mat4 modelCube = glm::mat4(1.0f);
		modelCube = glm::translate(modelCube, glm::vec3(0.0f, 0.0f, 0.0f));
		modelCube = glm::rotate(modelCube, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		modelCube = glm::scale(modelCube, glm::vec3(1.0f, 1.0f, 1.0f));

		glm::mat4 groundCube = glm::mat4(1.0f);
		groundCube = glm::translate(groundCube, glm::vec3(0.0f, -1.0f, 0.0f));
		groundCube = glm::rotate(groundCube, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		groundCube = glm::scale(groundCube, glm::vec3(15.0f, 1.0f, 15.0f));

		shader.use();
		shader.setMat4("View", view);
		shader.setMat4("Projection", projection);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glBindVertexArray(vaoGround);
		shader.setMat4("Model", groundCube);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glBindVertexArray(vaoCube);
			shader.setMat4("Model", modelCube);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glDisable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		screenShader.use();
		glBindVertexArray(vaoScreenQuad);
			glBindTexture(GL_TEXTURE_2D, fboTexture);
			glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		window.display();
	}

	glDeleteVertexArrays(1, &vaoCube);
	glDeleteVertexArrays(1, &vaoGround);
	glDeleteVertexArrays(1, &vaoScreenQuad);
	glDeleteBuffers(1, &vboCube);
	glDeleteBuffers(1, &vboScreenQuad);
	glDeleteRenderbuffers(1, &rbo);
	glDeleteFramebuffers(1, &fbo);
}