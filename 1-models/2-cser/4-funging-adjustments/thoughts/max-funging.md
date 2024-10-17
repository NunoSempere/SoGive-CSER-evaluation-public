## Model of max funging

Source: originally from Vasco Grillo

Comment: I think CSER is likely to behave less adversarially than literally funging as much as it can.

- Initially, CSER spends C_B_0 on the best projects, and C_0 - C_B_0 on others, where C_0 is the total spending at the beginning.
- After receiving a donation D restricted to the best projects, CSER will spend C_B_0 + D - F on the best projects, and C_0 - C_B_0 + F on others, where F is the amount of funging.
- CSER wants to maintain the initial allocation, so their target funging will be given by C_B_0/C_0 = (C_B_0 + D - F_target)/(C_0 + D) ⇔ F_target = (1 - C_B_0/C_0) × D.
- However, the amount of funging is limited to the unrestricted funding C_U_O_0 being spent on other projects, so the funging will be F = min(F_target, C_U_O_0).
- The additional benefits caused by D from:
    - The best projects will be B_B = (D - F) × CE_B, where CE_B is their marginal cost-effectiveness.
    - The other projects will be B_O = F × CE_O, where CE_O is their marginal cost-effectiveness.
- So the donation will have cost-effectiveness CE_D = (B_B + B_O)/D.
- Sanity checks:
    - If there is unlimited unrestricted funding:
        - C_U_O_0 = inf.
        - F = F_target.
        - B_B = CE_B × C_B_0/C_0 × D.
        - B_O = CE_O × (1 - C_B_0/C_0) × D.
        - CE_D = C_B_0/C_0 × CE_B + (1 - C_B_0/C_0) × CE_O, which makes sense because it equals the initial marginal cost-effectiveness of CSER.
    - If there is no unrestricted funding being spent on other projects:
        - C_U_O_0 = 0.
        - F = 0.
        - B_B = D × CE_B.
        - B_O = 0.
        - CE_D = CE_B, which makes sense because the donation would just be spent on the best projects.
