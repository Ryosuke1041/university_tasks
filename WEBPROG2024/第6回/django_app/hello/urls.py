from django.urls import path
from . import views

urlpatterns = [
    path('<msg>/<int:num>/', views.index),
]