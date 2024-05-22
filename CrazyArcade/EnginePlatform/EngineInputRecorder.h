#pragma once

class UEngineWindow;
class UEngineCore;
class UEngineInputRecorderReleaser;

class UEngineInputRecorder
{
	friend UEngineWindow;
	friend UEngineCore;
public:
	static void RecordStart(std::string_view _Text = "", int _MaxLength = 100);
	static void RecordEnd();
	static std::string GetText();

protected:


private:
	static bool Activeness;
	static int MaxLength;
	static bool ImeTickCalled;
	static bool IgnoreCompositionResult;

	static std::wstring WText;
	static std::string CombLetter;
	static HWND hWnd;
	static HIMC hIMC;
	static const std::string AllAlpha;
	static const std::string AllNumericAndSpecial;
	static const std::vector<int> AllSpecial;

	static void Init(HWND _hWnd);
	static bool IsNative();
	static void Tick(float _DeltaTime);
	static void ImeTick(LPARAM _lParam);
	static void Release();

private:
	inline static float DeleteTimer = 0.0f;
	inline const static float DeleteInterval = 0.075f;

	// ��ü ���� ����
	UEngineInputRecorder();
	~UEngineInputRecorder();

	class UEngineInputRecorderReleaser
	{
	public:
		~UEngineInputRecorderReleaser()
		{
			UEngineInputRecorder::Release();
		}
	};

	static UEngineInputRecorderReleaser Releaser;
};

