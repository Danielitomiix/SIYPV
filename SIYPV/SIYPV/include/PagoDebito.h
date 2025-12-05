#pragma once
#include "PagoStrategy.h"


class 
PagoDebito : public PagoStrategy {
public:
  
  
  PagoDebito() = default;
  ~PagoDebito() override = default;
  bool Pagar(double monto) override;
  std::string getNombreMetodo() const override;
};