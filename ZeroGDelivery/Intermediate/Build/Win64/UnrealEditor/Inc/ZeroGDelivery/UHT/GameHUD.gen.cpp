// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeroGDelivery/Public/HUD/GameHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameHUD() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AHUD();
UPackage* Z_Construct_UPackage__Script_ZeroGDelivery();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_AGameHUD();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_AGameHUD_NoRegister();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_UGameMenuWidget_NoRegister();
// End Cross Module References

// Begin Class AGameHUD
void AGameHUD::StaticRegisterNativesAGameHUD()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameHUD);
UClass* Z_Construct_UClass_AGameHUD_NoRegister()
{
	return AGameHUD::StaticClass();
}
struct Z_Construct_UClass_AGameHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "HUD/GameHUD.h" },
		{ "ModuleRelativePath", "Public/HUD/GameHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingGameWidget_MetaData[] = {
		{ "Category", "GameHUD" },
		{ "ModuleRelativePath", "Public/HUD/GameHUD.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_StartingGameWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGameHUD_Statics::NewProp_StartingGameWidget = { "StartingGameWidget", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameHUD, StartingGameWidget), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameMenuWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingGameWidget_MetaData), NewProp_StartingGameWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameHUD_Statics::NewProp_StartingGameWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameHUD_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGameHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeroGDelivery,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameHUD_Statics::ClassParams = {
	&AGameHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGameHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGameHUD_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameHUD_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGameHUD()
{
	if (!Z_Registration_Info_UClass_AGameHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameHUD.OuterSingleton, Z_Construct_UClass_AGameHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGameHUD.OuterSingleton;
}
template<> ZEROGDELIVERY_API UClass* StaticClass<AGameHUD>()
{
	return AGameHUD::StaticClass();
}
AGameHUD::AGameHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGameHUD);
AGameHUD::~AGameHUD() {}
// End Class AGameHUD

// Begin Registration
struct Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGameHUD, AGameHUD::StaticClass, TEXT("AGameHUD"), &Z_Registration_Info_UClass_AGameHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameHUD), 1579195397U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_3021992456(TEXT("/Script/ZeroGDelivery"),
	Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_HUD_GameHUD_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
