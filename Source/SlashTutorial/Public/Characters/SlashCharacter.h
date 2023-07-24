// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "Interfaces/PickupInterface.h"
// Generated
#include "SlashCharacter.generated.h"

class UInputMappingContext;
class UInputComponent;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class USlashOverlay;
class AItem;
class AController;

UCLASS()
class SLASHTUTORIAL_API ASlashCharacter : public ABaseCharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();

	/** <APawn> */
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	/** </APawn> */

	/** <ACharacter*/
	virtual void Jump() override;
	/** </ACharacter*/

	/** <AActor> */
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	/** </AActor> */

	/** <IHitInterface> */
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	/** </IHitInterface> */

	/** <IPickupInterface> */
	virtual void SetOverlappingItem(AItem* Item) override;
	virtual void AddSouls(ASoul* Soul) override;
	virtual void AddGold(ATreasure* Treasure) override;
	/** <IPickupInterface> */

protected:

	/** <AActor> */
	virtual void BeginPlay() override;
	/** </AActor> */

	/** Legacy Input Callbacks */
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);

	/** Enhanced Input functions */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	/** Action Input functions for both Legacy and Enhanced Input */
	void EKeyPressed();

	/** <ABaseCharacter> */
	virtual void Attack() override;
	/** </ABaseCharacter> */

	/** Combat */
	/** <ABaseCharacter> */
	virtual bool CanAttack() override;
	virtual void AttackEnd() override;
	virtual void Die() override;
	/** </ABaseCharacter> */
	void EquipWeapon(AWeapon* Weapon);
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();
	void PlayEquipMontage(const FName& SectionName);

	UFUNCTION(BluePrintCallable)
	void AttachWeaponToBack();

	UFUNCTION(BluePrintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BluePrintCallable)
	void FinishEquipping();

	UFUNCTION(BluePrintCallable)
	void HitReactEnd();

	/** Enhanced Input Properties */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* EKeyAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* AttackAction;

private:
	bool IsUnoccupied();
	void InitializeSlashOverlay();
	void SetHUDHealth();

	/** Character Components */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	UPROPERTY(VisibleAnywhere)
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};