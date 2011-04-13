#pragma once

#include "ui_widget.h"

// �� SetWidthHeight ��ʱ���������һ��Ϊ 0 ��������⽫�𲻵����á�
// ��Ϊ���ڼ��ľ����Ѿ���Ϊֱ�ߣ����� label �� SetWidthHeight ���������壬
// Width Ϊ���εĳ���Height Ϊ���εĳ�������� size ��С

class ENGINE_API UILabel : public UIWidget
{
public:
	UILabel();
	virtual ~UILabel() {}

	virtual void Render(RenderTarget& target) const;
	virtual void SetAlpha(float val);
    virtual void PostSetTopLeft();

	String& GetString() { return string_; }
	void SetString(const String& str);

	void SetSize(float size);
	void SetText(std::string text);
	void SetText(std::wstring text);
	void SetColor(Color color);

    virtual void OnMouseEnter();
    virtual void OnMouseLeft();
    virtual void OnPressed();

    // �����������ʱ�� Style ������껮����ʱ������ᱻ������������ָ�
    // Ĭ��Ϊ -1 ����ʾ��껮�뻮��ʱ��������
    void SetHoveredStyle(int style);

private:
	void RecomputeWidthHeight();

private:
	String string_;
    int hoveredStyle_;
};
