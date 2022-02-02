#include "Actor.h"


Actor::Actor(Component* parent_):Component(parent_) {}
Actor::~Actor() {}

void Actor::ListComponents() const {
	for (auto c : components) {
		std::cout << typeid(*c).name() << std::endl;
	}
}


bool Actor::OnCreate() {
	return true;
}
void Actor::OnDestroy() {}
void Actor::Update(const float deltaTime) {}
void Actor::Render()const {}






