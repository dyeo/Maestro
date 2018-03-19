#include <Maestro.h>

#include <Engine.h>
#include <SceneGraph.h>
#include <Graphics.h>

#include "TestGameMode.hpp"

int main(char *argc, char **argv)
{
	using namespace mae;
	Maestro::Initialize();
	Maestro::GetEngine()->AddSystem<SceneGraph>();
	Maestro::GetEngine()->AddSystem<Graphics>();
	Maestro::GetEngine()->gameModeStack.push(new TestGameMode());
	Maestro::GetEngine()->Run();
	Maestro::Destroy();
}