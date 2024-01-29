// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tantrum/TantrumCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTantrumCharacterBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumCharacterBase();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumCharacterBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Tantrum();
// End Cross Module References
	void ATantrumCharacterBase::StaticRegisterNativesATantrumCharacterBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATantrumCharacterBase);
	UClass* Z_Construct_UClass_ATantrumCharacterBase_NoRegister()
	{
		return ATantrumCharacterBase::StaticClass();
	}
	struct Z_Construct_UClass_ATantrumCharacterBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATantrumCharacterBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Tantrum,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TantrumCharacterBase.h" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATantrumCharacterBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATantrumCharacterBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATantrumCharacterBase_Statics::ClassParams = {
		&ATantrumCharacterBase::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATantrumCharacterBase_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ATantrumCharacterBase()
	{
		if (!Z_Registration_Info_UClass_ATantrumCharacterBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATantrumCharacterBase.OuterSingleton, Z_Construct_UClass_ATantrumCharacterBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATantrumCharacterBase.OuterSingleton;
	}
	template<> TANTRUM_API UClass* StaticClass<ATantrumCharacterBase>()
	{
		return ATantrumCharacterBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATantrumCharacterBase);
	ATantrumCharacterBase::~ATantrumCharacterBase() {}
	struct Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATantrumCharacterBase, ATantrumCharacterBase::StaticClass, TEXT("ATantrumCharacterBase"), &Z_Registration_Info_UClass_ATantrumCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATantrumCharacterBase), 1041124237U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_880747818(TEXT("/Script/Tantrum"),
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
