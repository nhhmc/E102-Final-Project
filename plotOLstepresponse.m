clear 
clc
%% PART 2 
% plot step response derived in part 1 
t1 = 0:1:300;
for i=1:length(t1)
    ystep(i) = 2.5 + (5/6)*exp(-2*t1(i)) + (-10/3)*(exp(-t1(i)/2));
end 


% import data from arduino
data = readmatrix('attempt10.txt');

% extract time values versus 
t = data(:, 1);
t = t(1:300);


% extract voltage values 
V = data(:, 2);
V = V(1:300);


% plot time versus voltage 
figure(1)
plot(t, V, 'b');
hold on 
plot(t1, ystep, 'r')
xlabel('Time (seconds)')
ylabel('Voltage (volts)')
legend('Experimental', 'Analytical')
title('Open Loop Step Response')



