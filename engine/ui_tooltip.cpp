#include "ui_tooltip.h"

#include "ui_cfg.h"
#include "util_drawable.h"
#include "util_string.h"

namespace UITooltip
{
  namespace
  {
    String tip_;
    Sprite background_;
    bool emptyTip_ = true;

    float setTime; // ��¼���õ�ʱ�䣬�����ӳ���ʾ
    float delayTime = kTooptipDelayTime; // �ӳٳ���ʱ��
    float fadeInTime = kTooptipFadeinTime; // �������ʱ�䳤��

    const float BACKGROUND_EXPEND_SIZE_X = 10.0f;
    const float BACKGROUND_EXPEND_SIZE_Y = 8.0f;
    const Color EMPTY_BACKGROUND_DEFAULT_COL = Color(97, 104, 255, 240);
  }

  void SetBackground(const Sprite& background)
  {
    background_ = background_;
  }

  void UITooltip::Set( const String& tip , float left /*= 0.0f*/, float top /*= 0.0f*/)
  {
    tip_ = tip;
    emptyTip_ = String_IsEmpty(tip);

    // ����λ��

    tip_.SetPosition(left + BACKGROUND_EXPEND_SIZE_X, top + BACKGROUND_EXPEND_SIZE_Y);

    // ���ñ����Ĵ�С������Ƿ�ͼƬ��������ͬʱ�����䱳����ɫ

    float width = tip_.GetRect().GetWidth() + BACKGROUND_EXPEND_SIZE_X * 2;
    float height = tip_.GetRect().GetHeight() + BACKGROUND_EXPEND_SIZE_Y * 2;
    background_.Resize(width, height);
    background_.SetPosition(left, top);
    if (background_.GetImage() == NULL)
      background_.SetColor(EMPTY_BACKGROUND_DEFAULT_COL);

    // ��¼����ʱ��

    setTime = static_cast<float>(clock());
  }

  void Draw(RenderTarget& target)
  {
    if (!emptyTip_ && (clock() - setTime > delayTime * 1000))
    {
      float alpha = 255 * (clock() - setTime - delayTime * 1000) / (fadeInTime * 1000);
      alpha = alpha > 255 ? 255 : alpha;

      SetAlpha(background_, alpha);
      SetAlpha(tip_, alpha);

      target.Draw(background_);
      target.Draw(tip_);
    }
  }

  void Reset()
  {
    Set(String());
  }

}
