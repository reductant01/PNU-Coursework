
export default function GalCard({galTitle, galWebmgalWebImageUrl, galPhotographyLocation}) {
  return (
    <div>
      <div className="text-sm bg-white border border-gray-200 rounded-lg shadow">
        <img className="rounded-t-lg" src={galWebmgalWebImageUrl} alt="img" />
        <div className="p-5">
          <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
            {galTitle}
          </h5>
          <p className="mb-3 font-normal text-gray-700 dark:text-gray-400">
            {galPhotographyLocation}
          </p>
        </div>
      </div>
    </div>
  )
}
