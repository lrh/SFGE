#pragma once

#include <util\i_get_instance.h>

#include "engine.h"

// �÷���
// ��ÿ֡��ȡ������ Event �����δ��� OnEvent ����
// ��Ҫ��ÿ֡�Ľ�β���� EndUpdate()

class ENGINE_API InputManager : public util::IGetInstance<InputManager> 
{
public:
	InputManager();

	virtual void OnEvent(const Event& eventReceived);

	bool IsKeyDown(Key::Code keyCode) const;
	bool IsMouseButtonDown(Mouse::Button button) const;

	bool GetKeyState(Key::Code keyCode) const;
	bool GetMouseButtonState(Mouse::Button button) const;

	bool IsKeyReleased(Key::Code keyCode) const;
	bool IsMouseButtonReleased(Mouse::Button button) const;

	int GetMouseX() const;
	int GetMouseY() const;

	void EndUpdate();

	void Reset();

private:
	void ResetDowns();
	void ResetStates();
	void ResetReleases();

private:
	bool keyDowns_[Key::Count];
	bool mouseButtonDowns_[Mouse::ButtonCount];

	bool keyStates_[Key::Count];
	bool mouseButtonStates_[Mouse::ButtonCount];

	bool keyReleases_[Key::Count];
	bool mouseButtonReleases_[Mouse::ButtonCount];

	int mouseX_;
	int mouseY_;
};