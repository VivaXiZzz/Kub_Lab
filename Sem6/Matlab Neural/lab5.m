t = linspace(0.3, 10, 100);
L = length(t);
z = cos(3*t - 15) ./ abs(t) + 0.15*randn(1,L);

x = [
    0, z(1:L-1);0, 0, z(1:L-2);0, 0, 0, z(1:L-3);0, 0, 0, 0, z(1:L-4);0, 0, 0, 0, 0, z(1:L-5)
];

net = feedforwardnet([20 1]);
net.trainParam.epochs = 1000;
net = train(net, x, z);

y = sim(net, x);

y = [y, zeros(1, 50)];

buffer = z(100:-1:96)';

for k = 101:150
    y(k) = sim(net, buffer);
    buffer = [y(k); buffer(1:4)];
end

plot(z, 'b'), hold on, grid on
plot(y, 'r'), hold off
xlabel('Время');
ylabel('Значение');
legend('Исходные данные', 'Прогноз');

error = z - y(1:100);

figure;
plot(t, error, 'b', 'LineWidth',1);
grid on;
xlabel('Время');
ylabel('Ошибка');
title('График ошибки предсказания');