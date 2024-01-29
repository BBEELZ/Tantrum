// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tantrum/TantrumPlayerController2.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTantrumPlayerController2() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumPlayerController2();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumPlayerController2_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Tantrum();
// End Cross Module References
	void ATantrumPlayerController2::StaticRegisterNativesATantrumPlayerController2()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATantrumPlayerController2);
	UClass* Z_Construct_UClass_ATantrumPlayerController2_NoRegister()
	{
		return ATantrumPlayerController2::StaticClass();
	}
	struct Z_Construct_UClass_ATantrumPlayerController2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATantrumPlayerController2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_Tantrum,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController2_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumPlayerController2_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "TantrumPlayerController2.h" },
		{ "ModuleRelativePath", "TantrumPlayerController2.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATantrumPlayerController2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATantrumPlayerController2>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATantrumPlayerController2_Statics::ClassParams = {
		&ATantrumPlayerController2::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumPlayerController2_Statics::Class_MetaDataParams), Z_Construct_UClass_ATantrumPlayerController2_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ATantrumPlayerController2()
	{
		if (!Z_Registration_Info_UClass_ATantrumPlayerController2.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATantrumPlayerController2.OuterSingleton, Z_Construct_UClass_ATantrumPlayerController2_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATantrumPlayerController2.OuterSingleton;
	}
	template<> TANTRUM_API UClass* StaticClass<ATantrumPlayerController2>()
	{
		return ATantrumPlayerController2::StaticClass();
	}
	ATantrumPlayerController2::ATantrumPlayerController2(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATantrumPlayerController2);
	ATantrumPlayerController2::~ATantrumPlayerController2() {}
	struct Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController2_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController2_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATantrumPlayerController2, ATantrumPlayerController2::StaticClass, TEXT("ATantrumPlayerController2"), &Z_Registration_Info_UClass_ATantrumPlayerController2, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATantrumPlayerController2), 3276993496U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController2_h_3579734818(TEXT("/Script/Tantrum"),
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController2_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumPlayerController2_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
