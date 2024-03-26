// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tantrum/TantrumPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTantrumPlayerController() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumPlayerController();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumPlayerController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Tantrum();
// End Cross Module References
	void ATantrumPlayerController::StaticRegisterNativesATantrumPlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATantrumPlayerController);
	UClass* Z_Construct_UClass_ATantrumPlayerController_NoRegister()
	{
		return ATantrumPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ATantrumPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseLookRightRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseLookRightRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlickThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FlickThreshold;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATantrumPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_Tantrum,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "TantrumPlayerController.h" },
		{ "ModuleRelativePath", "TantrumPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Look" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Base lookup rate, in deg/sec. Other scaling may affect final lookup rate.*/" },
#endif
		{ "ModuleRelativePath", "TantrumPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base lookup rate, in deg/sec. Other scaling may affect final lookup rate." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumPlayerController, BaseLookUpRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookUpRate_MetaData), Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookUpRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookRightRate_MetaData[] = {
		{ "Category", "Look" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Base lookup rate, in deg/sec. Other scaling may affect final lookup rate.*/" },
#endif
		{ "ModuleRelativePath", "TantrumPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base lookup rate, in deg/sec. Other scaling may affect final lookup rate." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookRightRate = { "BaseLookRightRate", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumPlayerController, BaseLookRightRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookRightRate_MetaData), Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookRightRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_JumpSound_MetaData[] = {
		{ "Category", "Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Sound Cur for Jumping Sound\n" },
#endif
		{ "ModuleRelativePath", "TantrumPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sound Cur for Jumping Sound" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_JumpSound = { "JumpSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumPlayerController, JumpSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_JumpSound_MetaData), Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_JumpSound_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_FlickThreshold_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "TantrumPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_FlickThreshold = { "FlickThreshold", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumPlayerController, FlickThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_FlickThreshold_MetaData), Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_FlickThreshold_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATantrumPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookUpRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_BaseLookRightRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_JumpSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumPlayerController_Statics::NewProp_FlickThreshold,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATantrumPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATantrumPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATantrumPlayerController_Statics::ClassParams = {
		&ATantrumPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATantrumPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ATantrumPlayerController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATantrumPlayerController()
	{
		if (!Z_Registration_Info_UClass_ATantrumPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATantrumPlayerController.OuterSingleton, Z_Construct_UClass_ATantrumPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATantrumPlayerController.OuterSingleton;
	}
	template<> TANTRUM_API UClass* StaticClass<ATantrumPlayerController>()
	{
		return ATantrumPlayerController::StaticClass();
	}
	ATantrumPlayerController::ATantrumPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATantrumPlayerController);
	ATantrumPlayerController::~ATantrumPlayerController() {}
	struct Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATantrumPlayerController, ATantrumPlayerController::StaticClass, TEXT("ATantrumPlayerController"), &Z_Registration_Info_UClass_ATantrumPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATantrumPlayerController), 1761526884U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController_h_2319999738(TEXT("/Script/Tantrum"),
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
