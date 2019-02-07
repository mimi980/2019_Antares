#pragma once

// Pour avoir M_PI
#define _USE_MATH_DEFINES
#include <math.h>

#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>
#include "Cablage.h"

class Pivot : public frc::PIDSubsystem
{
 private:
  rev::CANSparkMax m_moteur{CAN_PIVOT, rev::CANSparkMax::MotorType::kBrushed};
  rev::CANEncoder m_encodeur{m_moteur};

  const double m_angleParTick = 1.0;
  const double m_coefGravite = 1.0;

  // Petite fonction pour recuperer l'angle du pivot
  double GetAngle();

  // Petite fonction pour convertir des degrés en radians
  double Deg2rad(double angle){ return (angle*M_PI)/180.0; };

 public:
  Pivot();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;

  const double MILIEU = 0.0;
  const double CARGO_AVANT = 90.0;
  const double CARGO_ARRIERE = -90.0;
  const double FUSEE_AVANT = 45.0;
  const double FUSEE_ARRIERE = -45.0;
};
