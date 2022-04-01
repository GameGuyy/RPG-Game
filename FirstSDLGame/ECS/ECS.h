#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include "ECS.h"
#include "GameObject.h"

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastId = 0;
	//Every time we call 'lastId' we will get lastID
	return lastId++; // it will return next one
}
template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();//it will generate new lastID
	return typeID;
}
		
//check if Entity has a component Attached
constexpr std::size_t maxCompnents = 32;//maximum number of component can a c++ hold
using COmponentBitSet = std::bitset<maxCompnents>;
using COmponentArray = std::array<Component*,maxCompnents>;

class Component
{
public:
	Entity* entity;
	virtual void init(){}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component(){}
};
class Entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr < Component >> components;

	COmponentArray componentArray;
	COmponentBitSet componentBitSet;
public:
	void update()
	{
		for (auto& c : components) c->update();
		
	}
	void draw()
	{
		for (auto& c : components) c->draw();
	}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	template <typename T>bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}
	template<typename T,typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return  *static_cast<T*>(ptr);
		
	}
};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update()
	{
		for (auto& e : entities) e->update();

	}
	void draw()
	{
		for (auto& e : entities) e->update();
	}
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),[](const std::unique_ptr<Entity> &m_entity)
		{
				return !m_entity->isActive();
		}));
		std::end(entities);
	}
	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{e};
		entities.emplace_back((std::move(uPtr)));
		return *e;
	}
};