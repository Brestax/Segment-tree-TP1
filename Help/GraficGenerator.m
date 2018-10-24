clear all; close all;
pkg load miscellaneous;
pkg load io;
pkg load optim;

graphics_toolkit gnuplot

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ExecutionTime = dlmread('../Pruebas/ExecutionTime.csv','\t',1,0);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Figure_Handler = figure(1);
set(Figure_Handler,'PaperUnits','inches','PaperPosition',[0 0 6 4 ]);

Axis_Handler = axes;
set(Axis_Handler,'Box','on','FontName','Arial','FontSize',9,'GridLineStyle','--','LineWidth',0.5,'TickDir','in');
hold on;
grid on;

semilogx(ExecutionTime(:,3),ExecutionTime(:,1),'-m.','LineWidth',1.5);

semilogx(ExecutionTime(:,3),ExecutionTime(:,2),'-g.','LineWidth',1.5);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


LEGEND1=sprintf('Utilizando SegmentTree');
LEGEND2=sprintf('Sin utilizar SegmentTree');

axis([100 1000000 0.001 40]);

xlabel('Cantidad de querys [n]');
ylabel('Tiempo [s]');

Legend_Handler = legend(LEGEND1,LEGEND2);
legend('Boxon');
set(Legend_Handler,'FontName','Arial','FontSize',7,"location",'northwest');

print('Tiempo de Ejeuion.png','-dpng');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


return;
