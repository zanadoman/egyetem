<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;

class RegistrationController extends Controller
{
    public function store(Request $request)
    {
        Auth::login(User::create($request->validate([
            'email' => ['string', 'required', 'unique:users'],
            'password' => ['string', 'required'],
        ])));
        return redirect()
            ->route('messages.index')
            ->with('success', 'Registered.');
    }
}
