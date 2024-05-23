#include "PreCompile.h"
#include "CrazyArcadeCore.h"
#include "InitTestGameMode.h"
#include "MainPlayLevel.h"
#include "CrazyArcadeDebugWindow.h"
#include <EngineCore/EngineEditorGUI.h>
#include "MainTitleGameMode.h"
#include "LobbyTitleGameMode.h"
#include "ServerGameMode.h"
#include "EngineTestGameMode.h"
#include "IntroGameMode.h"

#include "Packets.h"
#include "ConnectionInfo.h"
#include "ServerManager.h"



std::shared_ptr<UEngineNet> UCrazyArcadeCore::Net = nullptr;
UServerManager UCrazyArcadeCore::NetManager;

UCrazyArcadeCore::UCrazyArcadeCore()
{
}

void UCrazyArcadeCore::End()
{
	std::shared_ptr<UEndSession> EndPacket = std::make_shared<UEndSession>();
	if (UCrazyArcadeCore::Net != nullptr) {
		EndPacket->SetSessionToken(UCrazyArcadeCore::Net->GetSessionToken());
		int a = UCrazyArcadeCore::Net->GetSessionToken();
		UCrazyArcadeCore::Net->Send(EndPacket);
		if (nullptr != Net)
		{
			Net->Off();
		}
		Net = nullptr;
	}
}

UCrazyArcadeCore::~UCrazyArcadeCore()
{
}

void UCrazyArcadeCore::Initialize()
{
	UEngineFont::Load("굴림");
	ResLoad();

	UEngineEditorGUI::CreateEditorWindow<UCrazyArcadeDebugWindow>("CrazyArcadeDebugWindow");


	//std::shared_ptr<UEngineNetWindow> NetManager = UEngineEditorGUI::CreateEditorWindow<UEngineNetWindow>("NetManager");
	//UCrazyArcadeCore::Net = NetManager;




	GEngine->CreateLevel<AInitTestGameMode>("InitTestLevel");
	GEngine->CreateLevel<AMainPlayLevel>("MainPlayLevel");
	GEngine->CreateLevel<AMainTitleGameMode>("TitleTestLevel");
	GEngine->CreateLevel<AServerGameMode>("ServerGameMode");
	GEngine->CreateLevel<ALobbyTitleGameMode>("LobbyTitleTestLevel");
	GEngine->CreateLevel<AEngineTestGameMode>("EngineTestLevel");
	GEngine->CreateLevel<AIntroGameMode>("IntroLevel");
	//GEngine->ChangeLevel("InitTestLevel");
	GEngine->ChangeLevel("TitleTestLevel");
}

void UCrazyArcadeCore::Tick(float _DeltaTime)
{
	UCrazyArcadeCore::NetManager.Update(_DeltaTime);
}

void UCrazyArcadeCore::ResLoad()
{
	// UI 리소스 로드
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("UI");

		std::vector<UEngineFile> AllFiles = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : AllFiles)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> AllDirectorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < AllDirectorys.size(); i++)
		{
			UEngineSprite::LoadFolder(AllDirectorys[i].GetFullPath());
		}
	}
	// Map 리소스 로드
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Map");

		std::vector<UEngineFile> AllFiles = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : AllFiles)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> AllDirectorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < AllDirectorys.size(); i++)
		{
			UEngineSprite::LoadFolder(AllDirectorys[i].GetFullPath());
		}
	}

	// Player 리소스 로드
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Player");

		std::vector<UEngineFile> AllFiles = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : AllFiles)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> AllDirectorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < AllDirectorys.size(); i++)
		{
			UEngineSprite::LoadFolder(AllDirectorys[i].GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Bomb");

		std::vector<UEngineFile> AllFiles = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : AllFiles)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> AllDirectorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < AllDirectorys.size(); i++)
		{
			UEngineSprite::LoadFolder(AllDirectorys[i].GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Item");

		std::vector<UEngineFile> AllFiles = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : AllFiles)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> AllDirectorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < AllDirectorys.size(); i++)
		{
			UEngineSprite::LoadFolder(AllDirectorys[i].GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Intro");

		std::vector<UEngineFile> AllFiles = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : AllFiles)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> AllDirectorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < AllDirectorys.size(); i++)
		{
			UEngineSprite::LoadFolder(AllDirectorys[i].GetFullPath());
		}
	}

}