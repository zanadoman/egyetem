<?php

use App\Http\Controllers\LoginController;
use App\Http\Controllers\MessageController;
use App\Http\Controllers\RegistrationController;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('authentication');
})->name('authentication');

Route::post('/registration', [RegistrationController::class, 'store'])
    ->name('registration.store');
Route::post('/login', [LoginController::class, 'store'])
    ->name('login.store');

Route::middleware(['auth'])->group(function () {
    Route::post('/logout', [LoginController::class, 'destroy'])
        ->name('logout');
    Route::get('/messages', [MessageController::class, 'index'])
        ->name('messages.index');
    Route::post('/messages', [MessageController::class, 'store'])
        ->name('messages.store');
    Route::put('/messages/{id}', [MessageController::class, 'update'])
        ->name('messages.update');
    Route::delete('/messages/{id}', [MessageController::class, 'destroy'])
        ->name('messages.destroy');
});

Route::get('/health', function () {
    return view('welcome');
})->name('health');
