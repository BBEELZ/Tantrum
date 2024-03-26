// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TantrumCharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANTRUM_TantrumCharacterBase_generated_h
#error "TantrumCharacterBase.generated.h already included, missing '#pragma once' in TantrumCharacterBase.h"
#endif
#define TANTRUM_TantrumCharacterBase_generated_h

#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_SPARSE_DATA
#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsThrowingObject); \
	DECLARE_FUNCTION(execIsPullingObject);


#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_ACCESSORS
#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATantrumCharacterBase(); \
	friend struct Z_Construct_UClass_ATantrumCharacterBase_Statics; \
public: \
	DECLARE_CLASS(ATantrumCharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tantrum"), NO_API) \
	DECLARE_SERIALIZER(ATantrumCharacterBase) \
	virtual UObject* _getUObject() const override { return const_cast<ATantrumCharacterBase*>(this); }


#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATantrumCharacterBase(ATantrumCharacterBase&&); \
	NO_API ATantrumCharacterBase(const ATantrumCharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATantrumCharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATantrumCharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATantrumCharacterBase) \
	NO_API virtual ~ATantrumCharacterBase();


#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_22_PROLOG
#define FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_SPARSE_DATA \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_ACCESSORS \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_INCLASS_NO_PURE_DECLS \
	FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANTRUM_API UClass* StaticClass<class ATantrumCharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h


#define FOREACH_ENUM_ECHARACTERTHROWSTATE(op) \
	op(ECharacterThrowState::None) \
	op(ECharacterThrowState::RequestingPull) \
	op(ECharacterThrowState::Pulling) \
	op(ECharacterThrowState::Attached) \
	op(ECharacterThrowState::Throwing) 

enum class ECharacterThrowState : uint8;
template<> struct TIsUEnumClass<ECharacterThrowState> { enum { Value = true }; };
template<> TANTRUM_API UEnum* StaticEnum<ECharacterThrowState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
