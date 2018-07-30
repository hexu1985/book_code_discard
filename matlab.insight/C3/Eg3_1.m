% Script Eg3_1
% Rational Approximation of pi

% Acquire the numerator/denominator limit...
M = input('Enter M:');

% Initializations...
pBest = 1;                      % Best numerator ``found so far''
qBest = 1;                      % Best denominator ``found so far''...
err_pq = abs(pBest/qBest - pi); % Error in current best fraction...

% Check out all possible denominators...
for q = 1:M
    % Initializations for the p-search...
    p0 = 1;
    e0 = abs(pi - p0/q);
    % For this q, find the best numerator p0...
    for p=1:M
        if abs(pi - p/q) < e0
            % A new best numerator has been found for this q...
            p0 = p;
            e0 = abs(pi - p/q);
        end
    end
    % Check to see if we have a new best quotient for this q...
    if  e0 < err_pq
        pBest = p0;
        qBest = q;
        err_pq = e0;
    end
end
MyPi = pBest/qBest;
% Display Results
clc
fprintf('M     = %1d\npBest = %1d\nqBest = %1d\n',...
        M,pBest,qBest)
fprintf('MyPi  = %17.15f\npi    = %17.15f\nerror = %17.15f\n\n',...
        MyPi,pi,err_pq)

