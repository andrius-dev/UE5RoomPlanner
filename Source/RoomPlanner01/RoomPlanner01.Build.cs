using UnrealBuildTool;

public class RoomPlanner01 : ModuleRules {

	public RoomPlanner01(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
			{"Core", "CoreUObject", "Engine", "InputCore", "SlateCore"});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}

}