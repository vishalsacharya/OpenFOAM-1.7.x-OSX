/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2009-2010 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "error.H"

#include "SpecularReflection.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template <class CloudType>
Foam::SpecularReflection<CloudType>::SpecularReflection
(
    const dictionary& dict,
    CloudType& cloud
)
:
    WallInteractionModel<CloudType>(dict, cloud, typeName)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template <class CloudType>
Foam::SpecularReflection<CloudType>::~SpecularReflection()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template <class CloudType>
void Foam::SpecularReflection<CloudType>::correct
(
    const wallPolyPatch& wpp,
    const label faceId,
    vector& U,
    scalar& Ei,
    label typeId
)
{
    vector nw = wpp.faceAreas()[wpp.whichFace(faceId)];
    nw /= mag(nw);

    scalar magUn = U & nw;

    if (magUn > 0.0)
    {
        U -= 2.0*magUn*nw;
    }
}


// ************************************************************************* //
