<?php

use App\Http\Controllers\MessageController;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/messages', [MessageController::class, 'index'])->name('messages.index');
Route::post('/messages', [MessageController::class, 'store'])->name('messages.store');
Route::put('/messages/{id}', [MessageController::class, 'update'])->name('messages.update');
Route::delete('/messages/{id}', [MessageController::class, 'destroy'])->name('messages.destroy');
