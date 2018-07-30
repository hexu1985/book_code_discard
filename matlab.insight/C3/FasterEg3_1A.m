% Script FasterEg3_1
% Rational Approximation of pi
% Assumes that the numerator/denominator limit M is initialized.

% Initializations...
pBest = 1;                      % Best numerator ``found so far''
qBest = 1;                      % Best denominator ``found so far''...
err_pq = abs(pBest/qBest - pi); % Error in current best fraction...

% Check out all possible denominators...
for q = 1:ceil(M/pi)
    % For this q, find the best numerator p0...
    pMinus = floor(pi*q); errMinus = abs(pi - pMinus/q);
    pPlus  = ceil(pi*q);  errPlus  = abs(pi - pPlus/q);
    if errMinus < errPlus
        p0 = pMinus; e0 = errMinus;
    else
        p0 = pPlus;  e0 = errPlus;
    end
    % Check to see if we have a new best quotient for this q...
    if  e0 < err_pq
        pBest = p0;
        qBest = q;
        err_pq = e0;
    end
end
MyPi = pBest/qBest;


