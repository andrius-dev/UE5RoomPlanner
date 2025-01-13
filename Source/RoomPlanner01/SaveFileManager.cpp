#include "SaveFileManager.h"

#include "Kismet/KismetSystemLibrary.h"

static IDesktopPlatform* GetDesktopPlatform() {
	if (!GEngine || !GEngine->GameViewport) {
		return nullptr;
	}
	return FDesktopPlatformModule::Get();
}

bool ASaveFileManager::SaveInteriorData(const FInteriorSaveData& SaveData) {
	const auto DefaultPath = UKismetSystemLibrary::GetProjectSavedDirectory();
	TArray<FString> OutFileNames;
	OpenSaveFileDialog(
		"Pick a folder to save your file",
		DefaultPath,
		"",
		OutFileNames
	);

	// todo: create a file to temp location and get its path
	return false;
}

FInteriorSaveData ASaveFileManager::LoadInteriorData() {
	return FInteriorSaveData();
}

bool ASaveFileManager::OpenFileDialog(
	const FString& DialogTitle,
	const FString& DefaultPath,
	const FString& FileTypes,
	TArray<FString>& OutFileNames
) {
	const auto DesktopPlatform = GetDesktopPlatform();
	if (!DesktopPlatform) {
		return false;
	}
	
	const auto ParentWindowHandle
		= GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	
	constexpr auto SelectionFlag = EFileDialogFlags::None;
	DesktopPlatform->OpenFileDialog(
		ParentWindowHandle,
		DialogTitle,
		DefaultPath,
		FString(""), // todo
		FileTypes,
		SelectionFlag,
		OutFileNames
	);
	
	return true;
}

bool ASaveFileManager::OpenSaveFileDialog(
	const FString& DialogTitle,
	const FString& DefaultPath,
	const FString& FileTypes,
	TArray<FString>& OutFileNames
) {
	const auto DesktopPlatform = GetDesktopPlatform();
	if (!DesktopPlatform) {
		return false;
	}
	
	const auto ParentWindowHandle
		= GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	
	constexpr auto SelectionFlag = EFileDialogFlags::None;
	DesktopPlatform->SaveFileDialog(
		ParentWindowHandle,
		DialogTitle,
		DefaultPath,
		FString(""), // todo
		FileTypes,
		SelectionFlag,
		OutFileNames
	);
	
	return true;
}
