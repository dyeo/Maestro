#pragma once

#define MAESTRO_DEBUG

#include <Maestro.h>
#include <Engine.h>
#include <GameMode.h>
#include <EntityHandle.h>
#include <Logging.h>

#include <SFML/Graphics.hpp>

class TestGameMode : public mae::GameMode
{
public:

	TestGameMode()
	{

	}

	virtual inline void OnCreate() override
	{
	}

	virtual inline void OnStart() override
	{
		ent1 = CreateEntity();
		//ent2 = CreateEntity();

		ent1->GetComponent<mae::Transform>();
		//ent2->GetComponent<mae::Transform>();

		t1 = static_cast<mae::Transform*>(ent1->GetComponent<mae::Transform>());
		//t2 = static_cast<mae::Transform*>(ent2->GetComponent<mae::Transform>());

		t1->SetLocalPosition(gm::vec3(0, 0, 0));
		t1->SetLocalScale(gm::vec3(10, 10, 10));
		//t2->SetParent(t1);
		//t2->SetLocalPosition(gm::vec3(1, 1, 1));

		tex.loadFromFile("./Assets/orb.png");
		s1 = sf::Sprite(tex); //s2 = sf::Sprite(tex);
	}

	virtual inline void OnUpdate() override
	{
		printf("nope\n");
		s1.setPosition(t1->GetLocalPosition().x, t1->GetLocalPosition().y);
		s1.setScale(t1->GetLocalScale().x, t1->GetLocalScale().y);
		//s2.setPosition(sf::Vector2f(t2->GetLocalPosition().x, t2->GetLocalPosition().y));
	}

	virtual inline void OnFixedUpdate() override
	{

	}

	virtual inline void OnRender() override
	{
		mae::Maestro::GetEngine()->window.draw(s1);
		//mae::Maestro::GetEngine()->window.draw(s2);
	}

	virtual inline void OnFinish() override
	{

	}

	virtual inline void OnDestroy() override
	{

	}

private:

	mae::EntityHandle ent1;
	mae::EntityHandle ent2;

	mae::Transform *t1;
	mae::Transform *t2;

	sf::Texture tex;
	sf::Sprite s1;
	sf::Sprite s2;

};
